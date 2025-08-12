#pragma once
#include <vector>
#include <optional>
#include "storage.h"
#include <unordered_map>

namespace storage {
template <typename T, typename IDT = int>
  requires std::copy_constructible<T> && std::equality_comparable<IDT>
class temp_storage : public IStorage<IDT, T> {
 private:
  std::unordered_map<IDT, T> data;

 public:
  temp_storage() = default;

  auto read() const -> std::vector<T> override;
  auto read(const IDT& id) const -> std::optional<T> override;
  auto deleteById(const IDT& id)
      -> std::pair<StorageError, std::optional<T>> override;
  auto create(IDT id, T value)
      -> std::pair<StorageError, std::optional<T>> override;
  auto update(const IDT& id, T value)
      -> std::pair<StorageError, std::optional<T>> override;
};
};  // namespace storage

#include "temp_storage.impl.h"
