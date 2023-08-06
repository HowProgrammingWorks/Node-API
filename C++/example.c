#include <node_api.h>

napi_value add(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  double a;
  napi_get_value_double(env, args[0], &a);
  double b;
  napi_get_value_double(env, args[1], &b);
  napi_value sum;
  double result = a + b;
  napi_create_double(env, result, &sum);
  return sum;
}

napi_value init(napi_env env, napi_value exports) {
  napi_value fn;
  napi_create_function(env, 0, 0, add, 0, &fn);
  napi_set_named_property(env, exports, "add", fn);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
