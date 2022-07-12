#include "cpp-httplib/httplib.h"
#include <iostream>

int main(void)
{
  using namespace httplib;

  Server svr;

  auto ret = svr.set_mount_point("/", "./public");
  if(!ret){
    std::cout<<"Directory not found! Exiting...";
    return 1;
  }else{
        std::cout<<"./public directory linked \n";
  }

  svr.Get("/hi", [](const Request& req, Response& res) {
    res.set_content("Hello World!", "text/plain");
  });


  svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
    auto numbers = req.matches[1];
    res.set_content(numbers, "text/plain");
  });


  svr.Get("/body-header-param", [](const Request& req, Response& res) {
    if (req.has_header("Content-Length")) {
      auto val = req.get_header_value("Content-Length");
    }
    if (req.has_param("key")) {
      auto val = req.get_param_value("key");
    }
    res.set_content(req.body, "text/plain");
  });


  svr.Get("/stop", [&](const Request& req, Response& res) {
    svr.stop();
  });


  svr.listen("0.0.0.0", 80);
}