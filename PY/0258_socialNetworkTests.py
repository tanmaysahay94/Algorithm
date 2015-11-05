#!usr/bin/env python

from q1 import *

def generic_test():
    global Users
    global Acquaintances
    global Messages
#testing add_friend function    
    add_friend("7", "3")
    assert(len(Acquaintances["7"]) == 4)
    assert(len(Acquaintances["3"]) == 7)
    try:
        add_friend("7")
    except TypeError:
        pass
    try:
        add_friend(sahay)
    except NameError:
        pass

#testing add_friends function
    add_friends("7", ["5", "6"])
    assert(len(Acquaintances["7"]) == 6)
    assert(len(Acquaintances["5"]) == 5)
    assert(len(Acquaintances["6"]) == 5)
    try:
        add_friends(Arpan.Kundu, Tanmay.Sahay, Shraddhan.Jain)
    except NameError:
        pass
    try:
        add_friends(7, 4, 2)
    except TypeError:
        pass

#testing remove_user function
    remove_user(8)
    remove_user("4")
    assert(len(Users) == 6)
    try:
        remove_user()
    except TypeError:
        pass
    try:
        remove_user(1, 2, 3, 4)
    except TypeError:
        pass

#testing get_friends function
    friends = get_friends(1)
    assert(type(friends) is tuple)
    assert(len(friends) is len(Acquaintances["1"]))
    try:
        get_friends(1)
    except TypeError:
        pass
    try:
        get_friends(Sahay)
    except NameError:
        pass

#testing get_friends_of_friends function
    friends_of_friends = get_friends_of_friends(1)
    assert(type(friends_of_friends) is tuple)
    assert(len(friends_of_friends) is 0)
    try:
        get_friends_of_friends(1, 2)
    except TypeError:
        pass
    try:
        get_friends_of_friends(Sahay)
    except NameError:
        pass

#testing send_message function
    send_message(1, 2, "Yo")
    send_message("1", "2", "Yo")
    try:
        send_message(A, B, C)
    except NameError:
        pass
    try:
        send_message(1, 2, 3, 4)
    except TypeError:
        pass

#testing send_group_message function
    send_group_message("1", ["2", "3"], "Ha")
    assert(len(Messages["2"]) is 5)
    assert(len(Messages["3"]) is 3)
    try:
        send_group_message(1, 2, 3, 4)
    except TypeError:
        pass
    try:
        send_group_message(1, ha, 2)
    except NameError:
        pass
    
#testing get_messages_from_friend function
    msg = get_messages_from_friend(2, 1)
    assert(len(msg) is 3)
    assert(type(msg) is tuple)
    msg = get_messages_from_friend(2, 2)
    assert(len(msg) is 0)
    try:
        get_messages_from_friend(1, 2, 4)
    except TypeError:
        pass
    try:
        get_messages_from_friend(1, 2, ha)
    except NameError:
        pass

#testing get_messages_from_all_friends function
    k = get_messages_from_all_friends(1)
    assert(type(k) is tuple)

#testing get_birth_day_messages function
    bday_msg = get_birth_day_messages(1)
    assert(type(bday_msg) is dict)
    try:
        get_birth_day_messages(1, 2)
    except TypeError:
        pass
    try:
        get_birth_day_messages(ha)
    except NameError:
        pass

#testing delete_message function
    delete_message(1, 'a')
    del_msg = delete_message(11, 'a')
    assert(del_msg is False)
    del_id = delete_message(1, 'a')
    assert(del_id is False)
    assert(len(Messages["1"]) == 1)
    try:
        delete_message()
    except TypeError:
        pass
    try:
        delete_message(Ha)
    except NameError:
        pass

#testing delete_messages function
    num = delete_messages(4, ('g', 'h'))
    try:
        delete_messages(1)
    except TypeError:
        pass
    try:
        delete_messages(1, haha)
    except NameError:
        pass

#testing delete_all_messages function
    deletion = delete_all_messages('4')
    assert(deletion is  not True)
    try:
        delete_all_messages()
    except TypeError:
        pass
    try:
        delete_all_messages(msg)
    except NameError:
        pass

#testing delete_messaged_from_friend function
    delete_messaged_from_friend("3", "1")
    assert(len(Messages["3"]) == 2)
    try:
        delete_messaged_from_friend(ha)
    except NameError:
        pass
    try:
        delete_messaged_from_friend(1, 2, 3)
    except TypeError:
        pass

#Main Function to run all the tests
if __name__ == '__main__':
    generic_test()
