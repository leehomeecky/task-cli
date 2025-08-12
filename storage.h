#pragma once
#include <vector>
#include <optional>
#include <concepts>


enum class StorageError {
  Success,
  KeyExists,
  StorageFull,
  KeyNotFound,
  InvalidInput
};


namespace storage {
template <typename T, typename IDT = int>
  requires std::copy_constructible<T> && std::equality_comparable<IDT>

class IStorage {
 public:
  virtual ~IStorage() = default;

  virtual auto read() const -> std::vector<T> = 0;
  virtual auto read(const IDT& id) const -> std::optional<T> = 0;

  virtual auto deleteById(const IDT& id)
      -> std::pair<StorageError, std::optional<T>> = 0;

  virtual auto create(IDT id, T value)
      -> std::pair<StorageError, std::optional<T>> = 0;

  virtual auto update(const IDT& id, T value)
      -> std::pair<StorageError, std::optional<T>> = 0;
};
};  // namespace storage
