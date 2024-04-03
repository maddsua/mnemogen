import { existsSync } from "https://deno.land/std@0.221.0/fs/exists.ts";

export default async () => {
	const sourceFileUrl = 'https://raw.githubusercontent.com/bitcoin/bips/master/bip-0039/english.txt';

	const sourceFileResponse = await fetch(sourceFileUrl);

	if (sourceFileResponse.status !== 200) {
		throw new Error(`Failed to fetch BIP-39 source file: http status ${sourceFileResponse.status}`);
	}

	const sourceFileContent = await sourceFileResponse.text();

	if (sourceFileContent.length < 13_000) {

		const errmsglines = [
			`Failed to fetch BIP-39 source file: sus content length (${sourceFileContent.length}).`,
			'The verified file size is over 13K so anthing below that is sus'
		];

		throw new Error(errmsglines.join('\r\n'));
	}

	const destDir = './var';

	if (!existsSync(destDir)) {
		Deno.mkdirSync(destDir, { recursive: true });
	}

	const tokensAsJson = JSON.stringify(sourceFileContent.replace(/[\r\n+]/g, '\n').split('\n'));

	Deno.writeTextFileSync(`${destDir}/bip39tokens.json`, tokensAsJson);
}
