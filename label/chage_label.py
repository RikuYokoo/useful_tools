import glob
import os

#files = glob.glob("3_labels")
dir_name="3_labels"
files = os.listdir(dir_name)
os.chdir(dir_name)

for file in files:
    data = []
    with open (file, "r") as f:
        label = f.readlines()
        for j in label:
            print(j[0]=='3')
            if j[0] == '3' :
                print("in")
                tmp = list(j)
                print(tmp)
                tmp[0] = '2'
                "".join(tmp)
                print(tmp)
                data.append(tmp)
                print("in")
            else :
                data.append(j)
    with open (file, "w") as f:
        for i in range (len(data)):
            f.write("".join(data[i]))

