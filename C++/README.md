# C++ addon with n-api for Node.js

- Install node-gyp
```
npm install -g node-gyp
```
- Compile to wasm
```
node-gyp configure
node-gyp build
```
- Run CJS and ESM examples
```
node 1-cjs.js
node 2-esm.mjs
```
