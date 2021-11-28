#include <string>
#include "Context.h"

int main() {
    Context context("my_DFS");

    const std::string action = "delete";
    const std::string path = "root/jojo.jpg";
    const std::string request = action + ":" + path;
    context.call(request);

    context.call("wtf?");
}