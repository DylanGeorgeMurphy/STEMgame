from PIL import Image

BluePrint = Image.open(str(input("ImageName\n>")))
FileName = str(input("FileName\n>"))

pix = BluePrint.load()

Content = ""

Colours = [
    [255, 255, 255],
    [1, 88, 142],
    [1, 137, 186],
    [3, 196, 177],
    [254, 221, 107],
    [170, 206, 47],
    [1, 1, 1],
    [1, 1, 1],
    [209, 101, 29]
    ]

for y in range(0, 32):
    for x in range(0, 32):
        Coloured = False

        R, G, B, A = pix[x, y]

        for index, k in enumerate(Colours):
            if([R, G, B]==k):
                Coloured = True
                #print("Pixel detected")
                Content = Content + str(index) + "\n"
                #print(str(index) + "\n")
        
        if Coloured == False:
            Content=Content + "0\n"
        
File = open(FileName, "w")
File.write(Content)
File.close()
