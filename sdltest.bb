MAINTAINER = "Marc Serdeliuc"
HOMEPAGE = "https://github.com/serdeliuk"
SUMMARY = "SDL2 test app"
SECTION = "examples"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
	file://sdltest-audio.c \
	file://sdltest-video.c \
	file://sdltest-keys.c \
	file://a.wav \
	file://a.bmp \
"

S = "${WORKDIR}"

DEPENDS = " \
	libsdl2 \
	alsa-lib \
	directfb \
"

LDFLAGS += " -lSDL2"

do_compile() {
    ${CXX} sdltest-audio.c -o sdltest-audio ${LDFLAGS}
    ${CXX} sdltest-video.c -o sdltest-video ${LDFLAGS}
    ${CXX} sdltest-keys.c -o sdltest-keys ${LDFLAGS}
}


do_install() {
        install -d ${D}${bindir}
        install -m 0755 sdltest-audio ${D}${bindir}
        install -m 0755 sdltest-video ${D}${bindir}
        install -m 0755 sdltest-keys ${D}${bindir}
	install -d ${D}${datadir}/sdltest
        install -m 0644 a.wav ${D}${datadir}/sdltest
        install -m 0644 a.bmp ${D}${datadir}/sdltest
}

pkg_postrm_${PN}() {
	rm -rf /usr/share/sdltest
}
