use napi_derive::napi;

#[napi]
pub fn add(a: i32, b: i32) -> i32 {
  return a + b;
}
