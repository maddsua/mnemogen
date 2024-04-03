import * as esbuild from 'https://deno.land/x/esbuild@v0.20.2/mod.js';

await esbuild.build({
	entryPoints: ['src/main.ts'],
	outfile: 'dist/bundle.js',
	bundle: true,
	format: 'esm',
});

await esbuild.stop();
