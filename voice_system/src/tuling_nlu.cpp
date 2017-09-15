#include "ros/ros.h"

#include <exception>
using namespace std;




int parseJsonResponse(string input)
{
    Json::
}

/*

*/
int HttpPostRequest(string input)
{
    string buffer;

    std::string strJson = "{";
    strJson += "\"key\" : \"56034b6eb8b2469f894e7d64821ce612\",";
    strJson += "\"info\" : ";
    strJson += "\"";
    strJson += input;
    strJson += "\"";
    strJson += "}";

    std::cout<<"post json string:"<<strJson<<std::endl;
    try
    {
        CURL *pCurl = NULL;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_ALL);

        pCurl = curl_easy_init();
        if(NULL != pCurl)
        {
            curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 8);
            curl_easy_setopt(pCurl, CURLOPT_URL, "thhp://www.tuling123.com/openapi/api");

            curl_slist *plist = curl_slist_append(NULL, "Content-Type:application/json:chaset=UTF-8");
            curl_eay_setopt(pCurl,CURLOPT_HTTPHEADER, plist);

            curl_easy_setopt()
        }
    }
}


void nlpCallback(const std_mags::String::ConstPtr& msg)
{
    std::cout<<"your question is:"<<msg->data<<std::endl;
    HttpPostRequest(msg->data);
}

/**
* main function
*/
int main(int argc, char **argv)
{
    ros::init(argc, argv, "tuling_nlu_node");
    ros::NodeHandle ndhandle;

    ros::Subscriber sub = ndHandle.subscribe("/voice/tuling_nlu_topic", 10, nluCallback);
    ros::Publisher pub = ndhandle.advertise<std_msgs:String>("/voice/xf_tts_topic", 10);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        if(flag)
        {
            std_msgs::String msg;
            msg.data = result;
            pub.publish(msg);
            flag = 0;
        }
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
