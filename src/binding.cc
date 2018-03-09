#include <node.h>
#include <string.h>

namespace caddress {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using v8::ArrayBuffer;
using v8::Array;
using v8::Integer;

/**
 * Get pointer address
 *
 * @param {ArrayBuffer} buffer
 *
 * @returns {ArrayBuffer} address
 */
void GetAddress(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 1) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")
        ));
        return;
    }

    if (!args[0]->IsArrayBuffer()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Arguments should be ArrayBuffer")
        ));
        return;
    }

    Local<ArrayBuffer> node_buffer = Local<ArrayBuffer>::Cast(args[0]);

    void *buffer = node_buffer->GetContents().Data();

    Local<ArrayBuffer> res_buffer = ArrayBuffer::New(isolate, sizeof(void *));
    memcpy(res_buffer->GetContents().Data(), &buffer, sizeof(void *));

    args.GetReturnValue().Set(res_buffer);
}

void init(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "getAddress", GetAddress);
}


NODE_MODULE(NODE_GYP_MODULE_NAME, init);

}
