FROM centor

WORKDIR /app

COPY DOCKERFILEDIR/ /app

RUN /httpserve/main.go
 
CMD ["/main"]