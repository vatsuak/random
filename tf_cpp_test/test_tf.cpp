// example.cpp
/*
#include <tensorflow/core/platform/env.h>
#include <tensorflow/core/public/session.h>
#include <tensorflow/core/protobuf/meta_graph.pb.h>

#include <iostream>

using namespace std;
using namespace tensorflow;

int main()
{   //change the path to the .meta file
	const string path = "/home/vatsuak/Desktop/ramdom_practice/tf_cpp_test/";
	const string pathToGraph = path + "-337931.meta";
	// const string pathToGraph = path + "-337931.meta";

	// const string checkpointPath = path + "models";

    Session* session;
    Status status = NewSession(SessionOptions(), &session);
    if (!status.ok()) {
        cout << status.ToString() << "\n";
        return 1;
    }
    cout << "Session successfully created.\n";

	// Read in the protobuf graph we exported
	MetaGraphDef graph_def;
	status = ReadBinaryProto(Env::Default(), pathToGraph, &graph_def);
	if (!status.ok()) {
		throw runtime_error("Error reading graph definition from " + pathToGraph + ": " + status.ToString());
	}
    cout << "Graph read!\n";
    cout << "====================\n\n\n\n\n\n\n";

	// Add the graph to the session
	status = session->Create(graph_def.graph_def());
	if (!status.ok()) {
		throw runtime_error("Error creating graph: " + status.ToString());
	}
}
*/
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"
#include "tensorflow/core/protobuf/meta_graph.pb.h"


// #include <ros/ros.h>
// #include <ros/package.h>
#include "tensorflow/c/c_api.h"
// #include "op_loader.h"



// #include "c_api.h"
// TF_Status* status_load = TF_NewStatus(); 
// TF_Library* lib_handle = TF_LoadLibrary("C:\\custom_op\\zero_out.dll", status_load);


using namespace tensorflow;

int main(int argc, char* argv[]) {
//   ros::init(argc, argv, "tensorflow_test_with_ros");
      
  // Initialize a tensorflow session
  Session* session;
  tensorflow::SessionOptions options = SessionOptions();
  options.config.mutable_gpu_options()->set_allow_growth(true);

  Status status = NewSession(options, &session);
//   TF_Status* state = TF_NewStatus();

//   TF_LoadLibrary("tf_sampling_so.so", state);

  // if (!status.ok()) {
  //   std::cout << status.ToString() << "\n";
  //   return 1;
  // }

  const string path = "/home/vatsuak/Desktop/ramdom_practice/tf_cpp_test/";
	// const string pathToGraph = path + "-300.meta";
	const string pathToGraph = path + "-337931.meta";

  // Read in the protobuf graph we exported.
  // See https://stackoverflow.com/a/43639305/1076564 for other ways of saving and restoring Tensorflow graphs.
  MetaGraphDef graph_def;
  // status = ReadBinaryProto(Env::Default(), ros::package::getPath("tensorflow_ros_test") + "/models/train.pb", &graph_def);
  status = ReadBinaryProto(Env::Default(), pathToGraph, &graph_def);
  // if (!status.ok()) {
  //   std::cout << status.ToString() << "\n";
  //   return 1;
  // }

  std::cout << "Graph read!\n";
  std::cout << "====================\n\n\n\n\n\n\n";

  // Add the graph to the session
  status = session->Create(graph_def.graph_def());
  // if (!status.ok()) {
  //   std::cout << status.ToString() << "\n";
  //   return 1;
  // }
  
    std::cout << "Graph attached!\n";
  std::cout << "====================\n\n\n\n\n\n\n";

  // status = session->Create(graph_def);
	// if (!status.ok()) {
	// 	throw runtime_error("Error creating graph: " + status.ToString());
	// }
  /*
  // Setup inputs and outputs:

  // Our graph doesn't require any inputs, since it specifies default values,
  // but we'll change an input to demonstrate.
  Tensor a(DT_FLOAT, TensorShape());
  a.scalar<float>()() = 3.0;

  Tensor b(DT_FLOAT, TensorShape());
  b.scalar<float>()() = 2.0;

  std::vector<std::pair<string, tensorflow::Tensor>> inputs = {
    { "a", a },
    { "b", b },
  };

  // The session will initialize the outputs
  std::vector<tensorflow::Tensor> outputs;

  // Run the session, evaluating our "c" operation from the graph
  status = session->Run(inputs, {"c"}, {}, &outputs);
  if (!status.ok()) {
    std::cout << status.ToString() << "\n";
    return 1;
  }

  // Grab the first output (we only evaluated one graph node: "c")
  // and convert the node to a scalar representation.
  auto output_c = outputs[0].scalar<float>();

  // (There are similar methods for vectors and matrices here:
  // https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/public/tensor.h)

  // Print the results
  std::cout << outputs[0].DebugString() << "\n"; // Tensor<type: float shape: [] values: 30>
  std::cout << output_c() << "\n"; // 30

  // Free any resources used by the session
  */
  session->Close();
  return 0;
}