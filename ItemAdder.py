ItemFile = open("Items.txt", 'r')
EnchantmentFile = open("Enchantment.txt", 'r')
itemList = ItemFile.readlines();
enchantmentList = EnchantmentFile.readlines();
print(itemList);
ItemFile.close();
moreItems = 'y'
while True:
    iType = input("Enchantment or Item? [E/I]: ")
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
    if (iType == 'I'):
        itemList.append(item)
    else:
        enchantmentList.append(item)
    if (moreItems != 'Y'):
        break
ItemFile = open("Items.txt", 'w')
EnchantmentFile = open("Enchantment.txt", 'w')
itemList[0] = str(len(itemList) - 1) + '\n'
enchantmentList[0] = str(len(enchantmentList) - 1) + '\n'
ItemFile.writelines(itemList)
EnchantmentFile.writelines(enchantmentList)
ItemFile.close()
EnchantmentFile.close()
