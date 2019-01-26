#include <string>
#include <iostream>
#include "CJsonObject.hpp"

void demo1()
{
    int iValue;
    std::string strValue;
    neb::CJsonObject oJson("{\"refresh_interval\":60,"
                        "\"dynamic_loading\":["
                            "{"
                                "\"so_path\":\"plugins/User.so\", \"load\":false, \"version\":1,"
                                "\"cmd\":["
                                     "{\"cmd\":2001, \"class\":\"neb::CmdUserLogin\"},"
                                     "{\"cmd\":2003, \"class\":\"neb::CmdUserLogout\"}"
                                "],"
                                "\"module\":["
                                     "{\"path\":\"im/user/login\", \"class\":\"neb::ModuleLogin\"},"
                                     "{\"path\":\"im/user/logout\", \"class\":\"neb::ModuleLogout\"}"
                                "]"
                             "},"
                             "{"
                             "\"so_path\":\"plugins/ChatMsg.so\", \"load\":false, \"version\":1,"
                                 "\"cmd\":["
                                      "{\"cmd\":2001, \"class\":\"neb::CmdChat\"}"
                                 "],"
                             "\"module\":[]"
                             "}"
                        "]"
                    "}");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson["dynamic_loading"][0]["cmd"][1]("class") << std::endl;
     oJson["dynamic_loading"][0]["cmd"][0].Get("cmd", iValue);
     std::cout << "iValue = " << iValue << std::endl;
     oJson["dynamic_loading"][0]["module"][0].Get("path", strValue);
     std::cout << "strValue = " << strValue << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     oJson.AddEmptySubObject("depend");
     oJson["depend"].Add("nebula", "https://github.com/Bwar/Nebula");
     oJson["depend"].AddEmptySubArray("bootstrap");
     oJson["depend"]["bootstrap"].Add("BEACON");
     oJson["depend"]["bootstrap"].Add("LOGIC");
     oJson["depend"]["bootstrap"].Add("LOGGER");
     oJson["depend"]["bootstrap"].Add("INTERFACE");
     oJson["depend"]["bootstrap"].Add("ACCESS");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson.ToFormattedString() << std::endl;
}

int main()
{
    using std::string;
    using std::cout;
    using std::endl;

    string str_contract = "contract";
    neb::CJsonObject oJson;
    oJson.AddEmptySubArray(str_contract);

    string str_parameter = "parameter";
    neb::CJsonObject parameter;
    parameter.AddEmptySubObject(str_parameter);
    string str_value = "value";
    parameter[str_parameter].AddEmptySubObject(str_value);
    parameter[str_parameter][str_value].Add("amount", 10000);

    oJson[str_contract].Add(parameter);

//    cout << oJson.ToFormattedString() << endl;
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    cout << parameter.ToFormattedString() << endl;

    string str = "{\"result\": true}";
    neb::CJsonObject test(str);
    bool ok = false;
    test.Get("result", ok);
    cout << ok << endl;
}

