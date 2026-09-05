# DUNE with Docker

The Docker setup supports two workflows:

- dev provides a compiler and development tools with the source tree mounted
  from the host.
- simulator builds a self-contained runtime image and starts the LAUV
  simulator.

Docker Engine with the Compose plugin is required.

Run the commands below from the `docker` directory:

~~~sh
cd docker
~~~

## Develop

Build the development image:

~~~sh
docker compose build dev
~~~

Configure and build DUNE:

~~~sh
docker compose run --rm dev cmake --preset dev
docker compose run --rm dev cmake --build --preset dev --parallel 2
~~~

The build directory is kept in the dune-build named volume. Open an
interactive development shell with:

~~~sh
docker compose run --rm dev
~~~

The image creates a non-root user with UID and GID 1000. Override these values
when the host user has different identifiers:

~~~sh
DUNE_UID="$(id -u)" DUNE_GID="$(id -g)" \
  docker compose build dev
~~~

Rebuild the image after changing the identifiers.

DUNE is a large project. The documented build uses two compiler processes to
avoid exhausting CPU and memory on development machines. Increase the number
after --parallel only when the machine has enough available memory. The
self-contained simulator image uses the same default; set DUNE_BUILD_JOBS when
building it to override that value.

## Run the simulator

Build and start the default LAUV simulator:

~~~sh
docker compose up --build simulator
~~~

The embedded HTTP interface is available at <http://localhost:8080>. Stop the
simulator with Ctrl-C, or from another terminal:

~~~sh
docker compose down
~~~

The simulator logs and database are stored in the dune-logs and dune-db named
volumes. Select another configuration or host port through environment
variables:

~~~sh
DUNE_CONFIG=lauv-simulator-1 DUNE_PROFILES=Simulation DUNE_HTTP_PORT=8081 \
  docker compose up simulator
~~~

The container publishes the HTTP port over TCP and the local IMC port over
UDP. Multicast discovery between a container and applications on the host can
vary by operating system and Docker network implementation; direct UDP
configuration may be needed for external tools.

The self-contained image intentionally excludes private* and user* trees from
its build context because those extensions can contain credentials and
deployment-specific data. They remain visible in the bind-mounted dev service.

## Clean generated Docker state

Stop the services without deleting their data:

~~~sh
docker compose down
~~~

To also delete the Docker-managed build, log, and database volumes:

~~~sh
docker compose down --volumes
~~~
