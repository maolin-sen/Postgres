FROM postgres:10.6 

MAINTAINER YourName@Tarwis Tech 

ENV PG_MAJOR 10 
ENV PG_FULL 10.6 

# Install the postgresql debugger
RUN apt-get update \ && apt-get install -y --no-install-recommends \ postgresql-$PG_MAJOR-pldebugger 

EXPOSE 5432 

#run below in DB to enable the extension 
#CREATE EXTENSION pldbgapi; 

#reference: 
#https://hub.docker.com/r/codejuggle/postgresql/~/dockerfile/ 
#https://docs.docker.com/engine/docker-overview/#docker-registries 
#https://github.com/docker-library/postgres/blob/2d40c8a89bfc888fb99463e919ac748cd54c0fcc/11/Dockerfile 
#https://gist.github.com/sethbergman/1a34dcf925badee366b46b7c52526701 
#https://github.com/sameersbn/docker-postgresql#enabling-extensions 
#https://github.com/docker-library/postgres/blob/f5a7e06b42aa14cad6edfaeefa676a5312d27618/10/Dockerfile
