'use strict';

const example = require('./build/Release/example.node');

const sum = example.add(3, 7);
console.log({ sum });

const res = example.addCallback(3, 7, (error, data) => {
  console.log({ data });
  return 'done';
});
console.log({ res });
