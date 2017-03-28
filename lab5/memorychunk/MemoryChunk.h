//
// Created by mrozolga on 28.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <string>
#include <cstring>
#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

        MemoryChunk(const MemoryChunk &xxx);

        MemoryChunk(MemoryChunk &&xxx);

        MemoryChunk &operator=(const MemoryChunk &xxx);

        MemoryChunk &operator=(MemoryChunk &&xxx);

        ~MemoryChunk();

    private:
        int8_t *ptr;
        size_t sz;

        void Copy(const MemoryChunk &xxx);
    };

}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
