FROM python:3.8-slim-buster

EXPOSE 8080

WORKDIR /app

COPY requirements.txt requirements.txt

RUN pip3 install -r requirements.txt

COPY . .

CMD ["python3", "./django_web/manage.py", "runserver", "0.0.0.0:8080"]
