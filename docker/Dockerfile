# syntax=docker/dockerfile:1

ARG DEBIAN_IMAGE=debian:bookworm-slim

FROM ${DEBIAN_IMAGE} AS development

ARG DUNE_UID=1000
ARG DUNE_GID=1000

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
      build-essential \
      bzip2 \
      ca-certificates \
      cmake \
      doxygen \
      gdb \
      git \
      gzip \
      libxml2-utils \
      python-is-python3 \
      python3 \
      valgrind \
    && rm -rf /var/lib/apt/lists/* \
    && groupadd --gid "${DUNE_GID}" dune \
    && useradd --create-home --uid "${DUNE_UID}" --gid "${DUNE_GID}" --shell /bin/bash dune

WORKDIR /workspace/source

RUN mkdir -p /workspace/source/build \
    && chown -R dune:dune /workspace

USER dune

CMD ["bash"]


FROM development AS builder

ARG DUNE_BUILD_JOBS=2

COPY --chown=dune:dune . /workspace/source

RUN --mount=type=cache,id=dune-build-cache,target=/workspace/source/build,uid=${DUNE_UID},gid=${DUNE_GID} \
    cmake --preset dev \
    && cmake --build --preset dev --parallel "${DUNE_BUILD_JOBS}" \
    && cmake --install build/dev --prefix /workspace/install


FROM ${DEBIAN_IMAGE} AS runtime

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
      libgcc-s1 \
      libstdc++6 \
    && rm -rf /var/lib/apt/lists/* \
    && groupadd --gid 10001 dune \
    && useradd --create-home --uid 10001 --gid 10001 --shell /usr/sbin/nologin dune

COPY --from=builder --chown=dune:dune /workspace/install /opt/dune

RUN mkdir -p /opt/dune/db /opt/dune/log \
    && chown -R dune:dune /opt/dune/db /opt/dune/log

WORKDIR /opt/dune

USER dune

EXPOSE 8080/tcp
EXPOSE 6002/udp

ENTRYPOINT ["/opt/dune/bin/dune"]
CMD ["-c", "lauv-simulator-1", "-p", "Simulation"]
