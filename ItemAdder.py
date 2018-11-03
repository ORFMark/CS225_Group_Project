ItemFile = open("Items.txt", 'r')
itemList = ItemFile.readlines();
print(itemList);
ItemFile.close();
moreItems = 'y'
while True:
    itemName = input("What is the name of the item: ")
    itemName = "'" + itemName + "'"
    itemTarget = input("What is the target stat: ")
    itemTarget = "'" + itemTarget + "'"
    itemValue = input("What is the stat increase or decrease: ")
    itemValue = "'" + itemValue + "'"
    itemPrecent = input("Is the value a precent [T/F]: ")
    itemPrecent = "'" + itemPrecent + "'"
    item = itemName + itemTarget + itemValue + itemPrecent + '\n'
    moreItems = input("Do you have more items[Y/N]: ")
    itemList.append(item)
    if (moreItems != 'Y'):
        break
ItemFile = open("Items.txt", 'w')
itemList[0] = str(len(itemList) - 1) + '\n'
ItemFile.writelines(itemList)
ItemFile.close()
