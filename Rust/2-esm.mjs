import { createRequire } from 'node:module';
const require = createRequire(import.meta.url);
const example = require('./example.node');

const sum = example.add(3, 7);
console.log({ sum });

const res = await example.addAsync(3, 7);
console.log({ res });
