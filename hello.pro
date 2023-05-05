CONFIG += debug

HEADERS += "headers/*" \
           "gameObjects/headers/*"

SOURCES += "main/*" \
           "sources/*" \
           "gameObjects/sources/*"

OBJECTS_DIR = "objects" \

QT += gui opengl widgets

TARGET = memes
