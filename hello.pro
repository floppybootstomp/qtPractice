CONFIG += debug

HEADERS += "headers/*" \
           "gameObjects/headers/*"

SOURCES += "main/*" \
           "sources/*" \
           "gameObjects/sources/*"

OBJECTS_DIR = "objects"

MOC_DIR = "moc"

QT += gui opengl widgets

TARGET = memes
