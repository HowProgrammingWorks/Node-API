#include <node_api.h>

static napi_value add(napi_env env, napi_callback_info info) {
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

#define DECLARE_NAPI_METHOD(name, func) \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value init(napi_env env, napi_value exports) {
  napi_property_descriptor addMethod = DECLARE_NAPI_METHOD("add", add);
  napi_define_properties(env, exports, 1, &addMethod);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
