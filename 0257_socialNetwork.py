#!usr/bin/env python

""" Social - A construct that contains various features of a rudimentary social networking website """

import time
import datetime

Users = {
        "1": ("Tanmay", "Bangalore",(1994, 12, 16)),
        "2": ("Nisarg", "Surat", (1995, 12, 20)),
        "3": ("Shraddhan", "Ajmer", (1995, 5, 25)),
        "4": ("Saksham", "New Delhi", (1994, 5, 15)),
        "5": ("Sikander", "Chandigarh", (1995, 5, 31)),
        "6": ("Arpan", "Warangal", (1994, 8, 4)),
        "7": ("Vivek", "Thane", (1996, 1, 12)),
        "8": ("Abhishek", "Bangalore", (1995, 4, 1))
        }

Acquaintances = {
        "1": ["2", "3", "4", "5", "6", "7", "8"],
        "2": ["1", "3", "4", "5", "6", "7", "8"],
        "3": ["1", "2", "4", "5", "6", "8"],
        "4": ["1", "2", "3", "8"],
        "5": ["1", "2", "3", "6"],
        "6": ["1", "2", "3", "5"],
        "7": ["1", "2", "8"],
        "8": ["1", "2", "3", "4", "7"]
        }

Messages = {
        "1": [("2", 'a', "Happy Birthday", (2013, 12, 16), time.localtime(time.time())), ("3", 'b', "yo", (2014, 1, 1), time.localtime(time.time()))],
        "2": [("4", 'c', "zzz", (2014, 3, 3), time.localtime(time.time())), ("5", 'd', "Hmm", (2012, 12, 12), time.localtime(time.time()))],
        "3": [("6", 'e', "Yeah", (2012, 12, 21), time.localtime(time.time())), ("7", 'f', "Hahahaha!", (2013, 1, 1), time.localtime(time.time()))],
        "4": [("8", 'g', "Beebop", (2014, 1, 15), time.localtime(time.time())), ("1", 'h', "kaka", (2013, 7, 29), time.localtime(time.time()))],
        "5": [("2", 'i', "yum", (2011, 1, 1), time.localtime(time.time())), ("3", 'j', "z", (2014, 1, 2), time.localtime(time.time()))],
        "6": [("4", 'k', "Yay", (2014, 1, 26), time.localtime(time.time())), ("5", 'l', "Nananana", (2013, 12, 31), time.localtime(time.time()))],
        "7": [("6", 'm', "Whine", (2013, 9, 22), time.localtime(time.time())), ("8", 'n', "Hmm", (2013, 12, 15), time.localtime(time.time()))],
        "8": [("1", 'o', "Msg", (2011, 11, 11), time.localtime(time.time())), ("2", 'p', "pizza!", (2012, 12, 12), time.localtime(time.time()))]
        }

def add_friend(user_id, friend_id):
#procedure to add a person to the user's friend list
#Assumption: Friendship is symmetric
    global Users
    global Acquaintances
    global Messages
    user_id = str(user_id)
    if user_id in Users:
        if friend_id in Users:
            Acquaintances[user_id].append(friend_id)
            Acquaintances[friend_id].append(user_id)
            return True
        else:
            return False
    else:
        return False

def add_friends(user_id, new_friends):
#procedure to add multiple people to the user's friend list
#Assumption: Friendship is symmetric
#all valid friend pairs are made
    global Users
    global Acquaintances
    user_id = str(user_id)
    for i in new_friends:
        i = str(i)
    if user_id in Users:
        new_friends = list(new_friends)
        if len(new_friends) > 1:
            for i in new_friends:
                if i not in Acquaintances[user_id]:
                    add_friend(user_id, i)
        elif len(new_friends) is 1:
            if new_friends not in Acquaintances[user_id]:
                add_friend(user_id, new_friends)
    else:
        return False

def remove_user(user_id):
#procedure to remove a user from the list of users
    global Users
    user_id = str(user_id)
    if user_id in Users:
        del Users[user_id]
        return True
    else:
        return False

def get_friends(user_id):
#procedure to get the friends of the given user
    global Users
    global Acquaintances
    user_id = str(user_id)
    if user_id in Users:
        if Acquaintances[user_id] == []:
            return None
        else:
            return tuple(Acquaintances[user_id])
    else:
        return False

def get_friends_of_friends(user_id):
#procedure to get the friends of friends of the given user
    global Users
    global Acquaintances
    friends_of_friends = []
    user_id = str(user_id)
    if user_id in Users:
        for i in Acquaintances[user_id]:
            friends_of_friends = friends_of_friends + Acquaintances[i]
        for i in friends_of_friends:
            if i in Acquaintances[user_id]:
                while i in friends_of_friends:
                    friends_of_friends.remove(i)
        while user_id in friends_of_friends:
            friends_of_friends.remove(user_id)
    else:
        return False
    return tuple(friends_of_friends)

def send_message(sender_id, receiver_id, msg):
#procedure to send a message
#msg is simply a string
    global Users
    global Messages
    now = datetime.datetime.now()
    sender_id = str(sender_id)
    receiver_id = str(receiver_id)
    ms = (sender_id, str(sender_id) + str(receiver_id) + str(time.time()), msg, (now.year, now.month, now.day), time.localtime(time.time()))
    if sender_id in Users and receiver_id in Users:
        Messages[receiver_id].append(ms)
    else:
        return False

def send_group_message(sender_id, recipient_list, msg):
#procedure to send a bulk message
#message is sent only if the sender and all the recipients are valid users
#msg is simply a string
    global Users
    global Messages
    sender_id = str(sender_id)
    truth_value = True
    recipient_list = list(recipient_list)
    for i in recipient_list:
        i = str(i)
    if sender_id not in Users:
        truth_value = False
    if len(recipient_list) > 1:
        for i in recipient_list:
            if i not in Users:
                truth_value = False
                break
        if truth_value:
            for i in recipient_list:
                send_message(sender_id, i, msg)
        return truth_value
    elif len(recipient_list) is 1:
        if recipient_list not in Users:
            truth_value = False
        if truth_value:
            Messages[recipient_list].append(ms)
        return truth_value

def get_messages_from_friend(receiver_id, friend_id):
#procedure to get messages from specified friend
    global Users
    global Messages
    received_messages = []
    receiver_id = str(receiver_id)
    friend_id = str(friend_id)
    if receiver_id not in Users or friend_id not in Users:
        return None
    else:
        for i in Messages[receiver_id]:
            sender_id, message_id, text, date_received, time_received = i
            if sender_id is friend_id:
                received_messages.append(i)
        return tuple(received_messages)

def get_messages_from_all_friends(receiver_id):
#procedure to get messages from all friends, i.e, all the messages in your inbox
    global Users
    global Messages
    receiver_id = str(receiver_id)
    if receiver_id in Users:
        return tuple(Messages[receiver_id])
    else:
        return False

def get_birth_day_messages(receiver_id):
#procedure to get birthday messages from all friends
    global Users
    global Messages
    receiver_id = str(receiver_id)
    if receiver_id in Users:
        name, place, date_of_birth = Users[receiver_id]
        bday_year, bday_month, bday_day = date_of_birth
        birthday_messages = []
        for i in Messages[receiver_id]:
            sender_id, message_id, text, date_received, time_received = i
            yy, mm, dd = date_received
            msg = (' ' + text).lower()
            if bday_month == mm and bday_day == dd: # and bool(msg.find("happy")) and bool(msg.find("birthday")):
                birthday_messages.append((sender_id, i))
        return dict(birthday_messages)
    else:
        return False

def delete_message(user_id, msg_id):
#procedure to delete a given message
    global Users
    global Messages
    user_id = str(user_id)
    truth_value = False
    if user_id in Users:
        for i in Messages[user_id]:
            sender_id, message_id, text, date_received, time_received = i
            if message_id == msg_id:
                Messages[user_id].remove(i)
                truth_value = True
                break
    return truth_value

def delete_messages(user_id, msg_list):
#procedure to delete a set of messages
    global Users
    global Messages
    user_id = str(user_id)
    if user_id in Users:
        msg_id_list = []
        for i in Messages[user_id]:
            msg_id_list.append(i[1])
        delete_count = 0
        for i in msg_list:
            if i in msg_id_list:
                if delete_message(user_id, i):
                    delete_count = delete_count + 1
        return delete_count
    else:
        return 0

def delete_all_messages(user_id):
#procedure to delete all messages of a given user
    global Users
    global Messages
    user_id = str(user_id)
    if user_id in Users:
        Messages[user_id] = []
        return True
    else:
        return False

def delete_messaged_from_friend(receiver_id, friend_id):
#procedure to delete all the messages from a given friend
    global Users
    global Messages
    receiver_id = str(receiver_id)
    friend_id = str(friend_id)
    if receiver_id in Users and friend_id in Users:
        for i in Messages[receiver_id]:
            sender_id, message_id, text, date_received, time_received = i
            if sender_id is friend_id:
                Messages[receiver_id].remove(i)
    else:
        return False
