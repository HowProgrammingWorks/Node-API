import { createRequire } from 'node:module';
const require = createRequire(import.meta.url);
const example = require('./build/Release/example.node');

const sum = example.add(3, 7);
console.log(sum);
