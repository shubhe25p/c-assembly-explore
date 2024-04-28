'You are a professional resume builder and a recruiter.\n Re-write the input as professionally as possible, adding vital, valuable information and skills.\n 
Enhance the input to showcase the relevant education, experience, and skills in a professional manner to effectively demonstrate value to potential employers.\n Do it for every value in your output {str(list(data_format))}.  '

User prompt: I am a college student with decent 


curl --request POST \
    --url http://127.0.0.1:8080/completion \
    --header "Content-Type: application/json" \
    --data '{"prompt": "You are a professional resume builder and a recruiter.\n","n_predict": 128, "temp": 0.9}'