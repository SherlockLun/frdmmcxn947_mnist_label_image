/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_LITE_MICRO_KERNELS_NEUTRON_H_
#define TENSORFLOW_LITE_MICRO_KERNELS_NEUTRON_H_

#include "tensorflow/lite/micro/micro_common.h"
#include "tensorflow/lite/micro/micro_profiler.h"

#include <vector>

namespace tflite {

TFLMRegistration* Register_NEUTRON_GRAPH();

const char* GetString_NEUTRON_GRAPH();

class NeutronProfilerInterface : public tflite::MicroProfilerInterface {
public:
    virtual ~NeutronProfilerInterface() {}
    virtual int addNeutronProfiling(char* profiling_buffer, size_t size) = 0;
    virtual std::vector<char*> getNeutronTraceBuffers() = 0;
    virtual std::vector<size_t> getNeutronTraceBufferSizes() = 0;
    virtual uint8_t getNeutronProfilingType() = 0;
};

}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_KERNELS_NEUTRON_H_
