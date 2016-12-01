## TWRP device tree for Samsung Galaxy Tab S 8.4 WiFi (klimtwifi)

Add to `.repo/local_manifests/klimtwifi.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
	<project path="device/samsung/klimtwifi" name="android_device_samsung_klimtwifi" remote="TeamWin" revision="android-6.0" />
</manifest>
```

Then run `repo sync` to check it out.

To build:

```sh
. build/envsetup.sh
lunch omni_klimtwifi-eng
make -j5 recoveryimage
```

Kernel sources are available at: https://github.com/jcadduono/android_kernel_samsung_universal5420/tree/twrp-6.0
