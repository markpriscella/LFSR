FROM gcc:10

WORKDIR /workspace

RUN apt-get update && \
  apt-get install -y libsfml-dev

COPY . .

RUN g++ -c photomagic.cpp; \
  g++ photomagic.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

ENTRYPOINT [ "/workspace/sfml-app" ]
