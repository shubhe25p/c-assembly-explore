# make a post request to the openai api

import requests
import json

def openai_request(prompt):
    url = "http://127.0.0.1/8080/completion"
    headers = {
        "Content-Type": "application/json",
    }   
    data = {
        "prompt": prompt,
        "n_predict": 128,
        "temp": 0.7,
    }
    response = requests.post(url, headers=headers, data=data)
    return response.json()

# Example usage
response = openai_request("Once upon a time in a land far, far away...")
print(response)