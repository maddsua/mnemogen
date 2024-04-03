import bip39tokens from '../var/bip39tokens.json' assert { type: 'json' };
import { getArgValue } from "./args.ts";
import { wrapInt, chunkify, parseIntOrUndefined } from './utils.ts';

const tokensNumber = parseIntOrUndefined(getArgValue('tokens')) || 10;
const alighIn = parseIntOrUndefined(getArgValue('align')) || 4;

const randomValues = new Uint16Array(tokensNumber);
crypto.getRandomValues(randomValues);

const indexes = Array.from(randomValues.map(item => wrapInt(item, bip39tokens.length - 1)));
const generatedTokens = indexes.map(item => bip39tokens[item]);

const printLines = chunkify(generatedTokens, alighIn).map(item => item.join(' '));

console.log('\nYo here\'s your new mnemonic phrase:\n--------');

for (const line of printLines) {
	console.log(line);
}

console.log('--------');
