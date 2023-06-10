#!/usr/bin/env python
# -*- coding: utf-8 -*-
import json
from typing import Union

import requests

# API
city_weather_url = 'http://www.weatherol.cn/api/home/getCurrAnd15dAnd24h'
# ua
user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36'


def get_headers():

    headers = {
        'user_agent': user_agent
    }
    return headers


def parse_data(weather_data):
    # """解析返回的数据，提取有用的内容
    with open("./weather.txt", "a") as f:
        f.write("")  # 自带文件关闭功能，不需要再写f.close()

        ret_dict = {}
        ret_dict['当前天气'] = weather_data['data']['current']['current']['weather']
        ret_dict['当前温度'] = weather_data['data']['current']['current']['temperature']
        ret_dict['风向'] = weather_data['data']['current']['current']['winddir']
        ret_dict['气压'] = weather_data['data']['current']['current']['airpressure'] + 'hpa'
        ret_dict['湿度'] = weather_data['data']['current']['current']['humidity'] + '%'

        f.write(ret_dict['当前天气']+'\n')
        f.write(ret_dict['当前温度']+'\n')
        f.write(ret_dict['风向']+'\n')
        f.write(ret_dict['气压']+'\n')
        f.write(ret_dict['湿度']+'\n')


    return ret_dict


def get_weather(city_id) -> Union[None, dict]:
    """
    根据城市ID获取天气信息
    """
    params = {
        'cityid': city_id
    }
    # 发出get请求
    response = requests.get(url=city_weather_url, headers=get_headers(), params=params)
    weather_json = response.text
    # print(weather_json)

    # 转换返回的字符串为json并解析
    weather_data = json.loads(weather_json)
    weather_dict = parse_data(weather_data)
    #print(response)
    return weather_dict

def main(a):
    with open("./weather.txt", "w") as f:
        f.write("")  # 自带文件关闭功能，不需要再写f.close()
    weather_dict = get_weather('101190701')
#    print(weather_dict)
    return a
