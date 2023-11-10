//计算文件的SHA-256哈希值
#include"random.h"
int calculateHash(const char *filename, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    // 实现文件哈希计算的代码，使用SHA-256哈希算法
    // 返回1表示计算成功，0表示失败
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("文件打开失败！");
        return 0; // 返回0表示计算失败
    }
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    size_t buffer_size = 8192;
    unsigned char buffer[buffer_size];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, buffer_size, file))) {
        SHA256_Update(&sha256_ctx, buffer, bytesRead);
    }
    unsigned char hashBytes[SHA256_DIGEST_LENGTH];
    SHA256_Final(hashBytes, &sha256_ctx);
    // 将哈希值转换为十六进制字符串
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i * 2], "%02x", hashBytes[i]);
    }
    fclose(file);
    return 1; // 返回1表示计算成功
}

