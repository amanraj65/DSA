#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BASE62 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define BASE 62
#define URL_LENGTH 7  // 6 characters for short URL + '\0'

// HashMap Node
typedef struct HashNode {
    char* shortUrl;
    char* longUrl;
    struct HashNode* next;
} HashNode;

// HashMap
typedef struct HashMap {
    HashNode** table;
    int size;
} HashMap;

// Create a new HashNode
HashNode* createNode(char* shortUrl, char* longUrl) {
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->shortUrl = strdup(shortUrl);
    node->longUrl = strdup(longUrl);
    node->next = NULL;
    return node;
}

// Create a new HashMap
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->table = (HashNode**)malloc(size * sizeof(HashNode*));
    map->size = size;
    for (int i = 0; i < size; i++) {
        map->table[i] = NULL;
    }
    return map;
}

// Hash function
unsigned int hashFunction(HashMap* map, char* shortUrl) {
    unsigned long int hashValue = 0;
    int i = 0;
    while (hashValue < ULONG_MAX && i < strlen(shortUrl)) {
        hashValue = hashValue * 37 + shortUrl[i];
        i++;
    }
    return hashValue % map->size;
}

// Insert a key-value pair into the HashMap
void insertHashMap(HashMap* map, char* shortUrl, char* longUrl) {
    unsigned int bucket = hashFunction(map, shortUrl);
    HashNode* node = map->table[bucket];
    if (node == NULL) {
        map->table[bucket] = createNode(shortUrl, longUrl);
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = createNode(shortUrl, longUrl);
    }
}

// Search for a value by key in the HashMap
char* searchHashMap(HashMap* map, char* shortUrl) {
    unsigned int bucket = hashFunction(map, shortUrl);
    HashNode* node = map->table[bucket];
    while (node != NULL && strcmp(node->shortUrl, shortUrl) != 0) {
        node = node->next;
    }
    if (node == NULL) {
        return NULL;
    } else {
        return node->longUrl;
    }
}

// Generate a base62 encoding from an integer
void encodeBase62(int num, char* shortUrl) {
    int index = 0;
    while (num > 0) {
        shortUrl[index++] = BASE62[num % BASE];
        num /= BASE;
    }
    shortUrl[index] = '\0';

    // Reverse the shortUrl to get the correct order
    int len = strlen(shortUrl);
    for (int i = 0; i < len / 2; i++) {
        char temp = shortUrl[i];
        shortUrl[i] = shortUrl[len - i - 1];
        shortUrl[len - i - 1] = temp;
    }
}

// URL Shortener Structure
typedef struct URLShortener {
    HashMap* map;
    int id;
} URLShortener;

// Initialize the URL Shortener
URLShortener* createURLShortener() {
    URLShortener* shortener = (URLShortener*)malloc(sizeof(URLShortener));
    shortener->map = createHashMap(1000);
    shortener->id = 1;
    return shortener;
}

// Shorten a URL
char* shortenURL(URLShortener* shortener, char* longUrl) {
    char* shortUrl = (char*)malloc(URL_LENGTH * sizeof(char));
    encodeBase62(shortener->id++, shortUrl);

    insertHashMap(shortener->map, shortUrl, longUrl);
    return shortUrl;
}

// Restore the original URL
char* restoreURL(URLShortener* shortener, char* shortUrl) {
    return searchHashMap(shortener->map, shortUrl);
}

int main() {
    URLShortener* shortener = createURLShortener();

    char* longUrl1 = "https://www.example.com/some/very/long/url";
    char* shortUrl1 = shortenURL(shortener, longUrl1);
    printf("Shortened URL: %s\n", shortUrl1);

    char* restoredUrl1 = restoreURL(shortener, shortUrl1);
    printf("Restored URL: %s\n", restoredUrl1);

    char* longUrl2 = "https://www.anotherexample.com/another/long/url";
    char* shortUrl2 = shortenURL(shortener, longUrl2);
    printf("Shortened URL: %s\n", shortUrl2);

    char* restoredUrl2 = restoreURL(shortener, shortUrl2);
    printf("Restored URL: %s\n", restoredUrl2);

    return 0;
}
