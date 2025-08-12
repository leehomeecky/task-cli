#pragma once
#include "temp_storage.h"

namespace storage {
template<typename T, typename IDT>
auto temp_storage<T, IDT>::read() const -> std::vector<T> {
  std::vector<T> result = {};
  result.reserve(data.size());

  for (std::pair<IDT, T>[key, value] : data) result.push_back(value);

  return result;
};

template<typename T, typename IDT>
auto temp_storage<T, IDT>::read(const IDT& id) const -> std::optional<T> {
  auto it = data.find(id);

  if (it == data.end()) return std::nullopt;

  return it->second;
};

template <typename T, typename IDT>
auto temp_storage<T, IDT>::create(IDT id, T value)
-> std::pair<StorageError, std::optional<T>> {
  auto [it, isInserted] =
      data.try_emplace(std::move(id), std::move(value));
  if (!isInserted) return {StorageError::KeyExists, std::nullopt};
  return {StorageError::Success, it->second};
}

template<typename T, typename IDT>
auto temp_storage<T, IDT>::update(const IDT& id, T value)
    -> std::pair<StorageError, std::optional<T>> {
  auto it = data.find(id);

  if (it == data.end()) return {StorageError::KeyNotFound, std::nullopt};

  it->second = std::move(value);
  return {StorageError::Success, it->second};
};
};

