## Rubik's Cube XPM Icon Generator

This program creates XPM icons with random color patterns in the likeness of a Rubik's cube.

###### Installation:

`make` then `make install`

###### As workspace icon:

When used with a bar that supports XBM and XPM formats (e.g. dzen), it can be used as a workspace icon.

![Icons GIF](rubikon.gif)

For inactive workspaces, use the XBM icon in the icons directory.

###### To generate icons on the fly

- Disable XPM icon caching if it exists
  - For dzen: change the value of `MAX_ICON_CACHE` in **dzen/draw.c** to **0** and rebuild dzen

- Mount a tmpfs directory for icon storage

- On workspace changes, run command to update icon - `rubikon > /tmp/rubik.xpm`
  - *Tip:* Use WM hooks to watch for workspace events

