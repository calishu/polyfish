# polyfish
> [!CAUTION]
> This project is still in heavy development; not even a foundation have been laid yet.

A scrolling-tiling window manager built on wayland _(wlroots)_

## Explanation/Concept
The biggest problem with tiling window managers is resizing and layout.
If an app suddenly opens a pop-up window, it instantly takes up half the screen.
Or are you familiar with the hassle of resizing windows using keyboard shortcuts?
Yes, I am. It's really annoying. My project attempts to solve this problem:
Instead of arranging apps in an area defined by the monitor, the area is scrollable, and the apps are placed to the right of the last app in the list. 
You can easily switch focus between windows, for example, with `SUPER+E` for the right window or `SUPER+Q` for the left.

## License
```
Copyright 2025 calishu

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```