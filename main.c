#include <concord/discord.h>

#define TOKEN ""

static void on_ready(struct discord *client,
                     const struct discord_ready *event) {
  discord_create_global_application_command(
      client, event->application->id,
      &(struct discord_create_global_application_command){
          .description = "devbadge",
          .name = "devbadge",
      },
      0);
}

int main(void) {
  struct discord *client = discord_init(TOKEN);
  discord_set_on_ready(client, &on_ready);
  discord_run(client);
}
