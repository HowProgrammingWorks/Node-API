'use strict';

const example = require('./example.node');

const sum = example.add(3, 7);
console.log({ sum });

example.addAsync(3, 7).then((res) => {
  console.log({ res });
});
