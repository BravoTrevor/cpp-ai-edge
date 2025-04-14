#include <onnxruntime_cxx_api.h>  

Ort::Session run_inference(const std::string& model_path, float* input) {  
  Ort::Env env;  
  Ort::Session session(env, model_path.c_str(), Ort::SessionOptions{});  

  // Allocate input/output tensors  
  Ort::Value input_tensor = Ort::Value::CreateTensor<float>(  
    Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeDefault),  
    input, 28*28, {1, 1, 28, 28}  
  );  

  const char* input_names[] = {"input"};  
  const char* output_names[] = {"output"};  
  auto outputs = session.Run(Ort::RunOptions{}, input_names, &input_tensor, 1, output_names, 1);  

  return outputs.front().GetTensorMutableData<float>();  
}  