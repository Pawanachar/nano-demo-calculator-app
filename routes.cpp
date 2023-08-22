#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world"};
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    if (!input)
    {
        return crow::response(400, "Bad Request: Invalid JSON");
    }

    int a = input["a"].i();
    int b = input["b"].i();
    int result = a + b;

    crow::json::wvalue responseJson;
    responseJson["result"] = result;

    return crow::response{responseJson};
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);

    if (!input)
    {
        return crow::response(400, "Bad Request: Invalid JSON");
    }

    int a = input["a"].i();
    int b = input["b"].i();
    int result = a - b;

    crow::json::wvalue responseJson;
    responseJson["result"] = result;

    return crow::response{responseJson};
}


