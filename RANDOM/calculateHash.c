//�����ļ���SHA-256��ϣֵ
#include"random.h"
int calculateHash(const char *filename, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    // ʵ���ļ���ϣ����Ĵ��룬ʹ��SHA-256��ϣ�㷨
    // ����1��ʾ����ɹ���0��ʾʧ��
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("�ļ���ʧ�ܣ�");
        return 0; // ����0��ʾ����ʧ��
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
    // ����ϣֵת��Ϊʮ�������ַ���
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i * 2], "%02x", hashBytes[i]);
    }
    fclose(file);
    return 1; // ����1��ʾ����ɹ�
}

