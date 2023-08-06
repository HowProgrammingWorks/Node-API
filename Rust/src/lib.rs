use napi_derive::napi;
use napi::bindgen_prelude::*;

#[napi]
pub fn add(a: i32, b: i32) -> i32 {
  return a + b;
}

#[napi]
pub async fn add_async(a: i32, b: i32) -> Result<i32> {
  Ok(a + b)
}
