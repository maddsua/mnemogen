
export const getArgValue = (arg: string): string | null => {

	const prefix = `--${arg}=`;

	const argEntry = Deno.args.find(item => item.startsWith(prefix));
	if (!argEntry) {
		return null;
	}

	const value = argEntry.slice(prefix.length);
	if (!value.length) {
		return null;
	}

	return value;
};
