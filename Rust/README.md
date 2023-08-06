# Rust addon with napi-rs for Node.js

- Install rust
  - For fedora:
```
sudo dnf install rust cargo
```
- Install napi-rs
```
npm i @napi-rs/cli
```
- See/edit `Cargo.toml` and `package.json`
- Compole example:
```
npm run build
```
- Run CJS and ESM examples
```
node 1-cjs.js
node 2-esm.mjs
```
