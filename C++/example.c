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

napi_value add_callback(napi_env env, napi_callback_info info) {
  size_t argc = 3;
  napi_value args[3];
  napi_get_cb_info(env, info, &argc, args, NULL, NULL);

  double a;
  napi_get_value_double(env, args[0], &a);

  double b;
  napi_get_value_double(env, args[1], &b);

  napi_value cb_args[2];
  double result = a + b;
  napi_get_null(env, &cb_args[0]);
  napi_create_double(env, result, &cb_args[1]);

  napi_value js_this, cb_result;
  napi_get_null(env, &js_this);
  napi_call_function(env, js_this, args[2], 2, cb_args, &cb_result);
  return cb_result;
}

napi_value init(napi_env env, napi_value exports) {
  napi_value fn_add;
  napi_create_function(env, 0, 0, add, 0, &fn_add);
  napi_set_named_property(env, exports, "add", fn_add);

  napi_value fn_add_callback;
  napi_create_function(env, 0, 0, add_callback, 0, &fn_add_callback);
  napi_set_named_property(env, exports, "addCallback", fn_add_callback);

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
