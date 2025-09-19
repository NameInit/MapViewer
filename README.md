# MapViewer

Приложение для просмотра погодных карт, загружаемых из сети.

## Сборка

```bash
qmake
make
```

Или используйте Makefile в папке `build/`

## Требования

- QT 6.x
- C++17

## Примеры координат

- Проспект Мира: `55.780228, 37.632677, zoom: 16`
- Москва: `55.749531, 37.616329, zoom: 8`

## Тестирование

Для проверки координат используйте:
- https://epsg.io/map
- https://docs.maptiler.com/google-maps-coordinates-tile-bounds-projection/
