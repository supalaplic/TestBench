import sys, os

PNG = "png"
JPG = "jpg"

IMAGE_TYPE = "image"

dataId = 0

def createMeta(path, fileName):
    path = replace(path, '\\', '/')

    #exclude Debug folder
    if path.find("..\..\Debug") == 0:
        return

    extension = getFileExtension(fileName)

    if(extension == PNG or extension == JPG):
        imageMeta(path, fileName, extension)
    return

def imageMeta(path, fileName, extension):
    filePath = path + "/" + fileName
    meta = open(filePath + ".meta", "wb")
    #type:TYPE
    meta.write("type:" + IMAGE_TYPE + "\n")

    # id:ID
    meta.write("id:")
    meta.write(fileName.split('.')[0] + str(getCurrId()));
    meta.write("\n");

    #path:PATH
    #the first ../.. is removed from path,. If create_meta is not located in ./src/tools this needs to be changed
    #
    meta.write("path:");
    meta.write(filePath[4:] + "\n")

    #settings

    #hasAlpha:HAS_ALPHA
    meta.write("hasAlpha:" + str(False))

    meta.close()
    return

def getFileExtension(fileName):
    data = fileName.split('.')
    return data[len(data) - 1]

def getCurrId():
    global dataId;
    dataId = dataId + 1
    return dataId

def replace(input, toReplace, replaceWith):
    for i in range(0, len(input) - 1):
        if(input[i] == toReplace):
            newInput = input[:i]
            newInput += replaceWith
            newInput += input[i+1:]
            input = newInput
    return input

root = "..\.."

for path, subdirs, files in os.walk(root):
    for file in files:
        createMeta(path, file)
