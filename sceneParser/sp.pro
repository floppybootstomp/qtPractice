CONFIG += debug

HEADERS += "headers/*" \

SOURCES += "main/*" \
           "sources/*" \

RESOURCES += "../res.qrc"

OBJECTS_DIR = "objects"

MOC_DIR = "moc"

QT += gui opengl widgets

TARGET = memes

QMAKE_CXXFLAGS += -Os
