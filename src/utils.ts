
export const wrapInt = (value: number, max: number) => {

	if (value <= max) {
		return value;
	}

	return value % max;
};

export const chunkify = <T>(data: Array<T>, chunkSize: number) => {

	const chunks: Array<T>[] = [];
	
	for (let i = 0; i < data.length; i += chunkSize) {
	  const chunk = data.slice(i, i + chunkSize);
	  chunks.push(chunk);
	}

	return chunks;
};

export const parseIntOrUndefined = (input?: string | null) => {

	if (typeof input !== 'string') {
		return undefined;
	}

	const value = parseInt(input);
	if (isNaN(value)) {
		return undefined;
	}

	return value;
};
